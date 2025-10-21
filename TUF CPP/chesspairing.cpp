#include <bits/stdc++.h>
using namespace std;

struct Player {
    int id;
    string name;
    int rating;
    int points = 0;
    int wins = 0;
    int losses = 0;
    int draws = 0;
    int sbScore = 0;
};

// trim helper
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// Robust CSV parser
vector<vector<string>> parseCSV(const string &filename) {
    ifstream file(filename);
    vector<vector<string>> result;
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << "\n";
        return result;
    }

    while (getline(file, line)) {
        if (line.empty()) continue;

        // Remove BOM if present
        if (line.size() >= 3 && 
            (unsigned char)line[0] == 0xEF &&
            (unsigned char)line[1] == 0xBB &&
            (unsigned char)line[2] == 0xBF) {
            line = line.substr(3);
        }

        vector<string> row;
        string cell;
        stringstream ss(line);

        while (getline(ss, cell, ',')) {
            row.push_back(trim(cell));
        }
        if (!row.empty()) result.push_back(row);
    }
    return result;
}

// Write CSV
void writeCSV(const string &filename, const vector<vector<string>> &data) {
    ofstream file(filename);
    for (auto &row : data) {
        for (size_t i = 0; i < row.size(); i++) {
            file << row[i];
            if (i + 1 < row.size()) file << ",";
        }
        file << "\n";
    }
}

// Round Robin pairings
vector<pair<Player, Player>> roundRobin(vector<Player> &players, int round) {
    int n = players.size();
    vector<pair<Player, Player>> pairings;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    if (n % 2 == 1) {
        idx.push_back(-1); // bye
        n++;
    }

    for (int r = 0; r < round; r++) {
        for (int i = 0; i < n / 2; i++) {
            int p1 = idx[i], p2 = idx[n - 1 - i];
            if (p1 != -1 && p2 != -1)
                pairings.push_back({players[p1], players[p2]});
        }
        rotate(idx.begin() + 1, idx.end() - 1, idx.end());
    }
    return pairings;
}

// Swiss pairings (simple)
vector<pair<Player, Player>> swissSystem(vector<Player> &players, int round) {
    sort(players.begin(), players.end(), [](auto &a, auto &b) {
        if (a.points == b.points) return a.rating > b.rating;
        return a.points > b.points;
    });

    vector<pair<Player, Player>> pairings;
    for (size_t i = 0; i + 1 < players.size(); i += 2) {
        pairings.push_back({players[i], players[i + 1]});
    }
    return pairings;
}

// Knockout
vector<pair<Player, Player>> knockout(vector<Player> &players, int round) {
    vector<pair<Player, Player>> pairings;
    for (size_t i = 0; i + 1 < players.size(); i += 2) {
        pairings.push_back({players[i], players[i + 1]});
    }
    return pairings;
}

// SB score (placeholder)
void updateSB(vector<Player> &players) {
    for (auto &p : players) {
        p.sbScore = p.points * 2;
    }
}

// Save standings
void saveStandings(const string &filename, vector<Player> &players) {
    updateSB(players);
    sort(players.begin(), players.end(), [](auto &a, auto &b) {
        if (a.points == b.points) return a.sbScore > b.sbScore;
        return a.points > b.points;
    });

    vector<vector<string>> out;
    out.push_back({"ID", "Name", "Rating", "Points", "SB"});
    for (auto &p : players) {
        out.push_back({
            to_string(p.id),
            p.name,
            to_string(p.rating),
            to_string(p.points),
            to_string(p.sbScore)
        });
    }
    writeCSV(filename, out);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " players.csv [roundrobin|swiss|knockout] <round-number>\n";
        return 1;
    }

    string playersFile = argv[1];
    string system = argv[2];
    int round = stoi(argv[3]);

    auto table = parseCSV(playersFile);
    if (table.size() < 2) {
        cerr << "players.csv has no data.\n";
        return 1;
    }

    vector<Player> players;
    for (size_t i = 1; i < table.size(); i++) {
        auto &row = table[i];
        if (row.size() < 2) continue;
        Player p;
        try {
            p.id = stoi(row[0]);
        } catch (...) {
            continue;
        }
        p.name = row[1];
        if (row.size() >= 3) {
            try { p.rating = stoi(row[2]); }
            catch (...) { p.rating = 0; }
        } else {
            p.rating = 0;
        }
        players.push_back(p);
    }

    if (players.empty()) {
        cerr << "No valid players loaded.\n";
        return 1;
    }

    vector<pair<Player, Player>> pairings;
    if (system == "roundrobin") pairings = roundRobin(players, round);
    else if (system == "swiss") pairings = swissSystem(players, round);
    else if (system == "knockout") pairings = knockout(players, round);
    else {
        cerr << "Unknown system: " << system << "\n";
        return 1;
    }

    vector<vector<string>> out;
    out.push_back({"White", "Black"});
    for (auto &pr : pairings) {
        out.push_back({pr.first.name, pr.second.name});
    }
    writeCSV("pairings_round" + to_string(round) + ".csv", out);

    saveStandings("standings.csv", players);

    cout << "✅ Pairings and standings generated.\n";
    return 0;
}

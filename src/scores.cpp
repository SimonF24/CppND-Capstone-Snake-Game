#include <fstream>
#include <iostream>
#include <vector>

#include "scores.h"

Scores::Scores() {
    std::ifstream scorefile("scores.txt");
    if (scorefile.is_open()) {
        std::string line;
        vector<int> scores(10);
        for (int i = 0; i < 10; i++) {
            getline(scorefile, line);
            scores[i] = std::stoi(line);
        }
        _scores = std::make_unique<vector<int>>(scores.begin(), scores.end());
        scorefile.close();
    } else { // If no scores.txt file is present, initialize the scores to all zeros
        _scores = std::make_unique<vector<int>>(10); // This zero initializes the vector
    }
}

void Scores::AddScore(const int newScore) {
    int left = 0;
    int right = _scores->size() - 1;
    if (newScore > (*_scores)[right]) { // Make sure the score is big enough to be added to the top ten
        int mid, position = right;
        while (left <= right) { // binary search to find the correct position in the vector to add the new score
            mid = left + (right - left) / 2;
            if ((*_scores)[mid] == newScore) {
                position = mid;
                break;
            } else if ((*_scores)[mid] > newScore) {
                left = mid + 1;
            } else {
                position = mid;
                right = mid - 1;
            }
        }
        _scores->insert(_scores->begin() + position, newScore);
        _scores->pop_back();
    }
}

void Scores::SaveScores() {
    std::ofstream scorefile;
    scorefile.open("scores.txt");
    for (int score : *_scores) {
        scorefile << score << "\n";
    }
    scorefile.close();
}
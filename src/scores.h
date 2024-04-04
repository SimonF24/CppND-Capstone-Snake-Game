#ifndef SCORES_H
#define SCORES_H

#include <memory>
#include <vector>

using std::vector;

class Scores {
    public:
        Scores();
        vector<int> GetScores() { return *_scores; };
        void AddScore(const int score);
        void SaveScores();

    private:
        std::unique_ptr<vector<int>> _scores; // vector of the top 10 scores, the start is the highest score
};

#endif
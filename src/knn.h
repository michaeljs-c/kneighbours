#include "csv_utils.h"
#include <math.h>
#include <cmath>

#include <iostream>
#include <numeric>      // std::iota
#include <algorithm>    // std::sort, std::stable_sort

int mostCommon(vector<int> vec) {

    sort(vec.begin(), vec.end());

    int element;
    int count = 0;
    int max_element;
    int max_count = 0;

    for (int i=0; i<vec.size(); ++i){

        if (vec[i] != element) {
            if (count > max_count) {
                max_count = count;
                max_element = element;
            }
            element = vec[i];
            count = 1;
        }
        else {
            ++count;
        }
    }
    if (count > max_count) {
        max_element = element;
    }
    return max_element;
}

vector<int> getKIndices(vector<double> V, int k, string minOrMax="min") {
    vector<int> K;
    std::vector<size_t> indices(V.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::partial_sort(indices.begin(), indices.begin() + 5, indices.end(),
                    [&](size_t A, size_t B) {
                        return minOrMax == "max"? V[A] > V[B]: V[A] < V[B];
                    });

    for (int i=0; i < k; ++i) {
        K.push_back(indices[i]);
    }
    return K;
}

class KNNClassifier {
    public:
    KNNClassifier(int k = 3) {
        this->k = k;
    }

    public:
        vector<vector<double>> X;
        vector<int> y;
        int k;


        void fit(vector<vector<double>> X, vector<int> y) {
            this->X = X;
            this->y = y;
        }
        vector<int> predict(vector<vector<double>> X) {
            vector<int> y_preds;
            for (int i=0; i<X.size(); ++i) {
                y_preds.push_back(singlePredict(X[i]));
            }
            return y_preds;
        }

        int singlePredict(vector<double> x) {
            vector<double> distances;

            for (int i=0; i<X.size(); ++i) {
                double squaredSum = 0;
                for (int j=0; j<X[j].size(); ++j) {
                    squaredSum += pow(X[i][j] - x[j], 2);
                }
                distances.push_back(sqrt(squaredSum));
            }
        
            vector<int> idxs = getKIndices(distances, k);
            vector<int> y_vals{idxs.begin(), idxs.begin()+k};
            
            for (int i=0; i<k; ++i) {
                y_vals[i] = y[y_vals[i]];
            }
            int pred = mostCommon(y_vals);
            return pred;
        }
};
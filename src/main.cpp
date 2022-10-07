#include "knn.h"


int main() {
    
    vector<vector<double>> X_train = readCsvNumeric("train_x.csv");
    vector<vector<double>> X_test = readCsvNumeric("test_x.csv");
    // vector<vector<double>> y = readCsvNumeric("train_y.csv");

    vector<int> y_train = {1,1,1,2,2,2,3,3,3,4};

    KNNClassifier knn = KNNClassifier(3);
    knn.fit(X_train, y_train);
    vector<int> preds = knn.predict(X_test);

    cout << "Data:" << endl;
    showMatrix(X_train);
    cout << endl;

    cout << "Predictions:" << endl;
    showMatrix(preds);
    cout << endl;

    return 0;
}
 
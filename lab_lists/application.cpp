//the application :
#include <iostream>
#include <string>

using namespace std;

#define MAX 10  

class ScoreList {//ourlist 
private:
    int scores[MAX];
    int size;         

public:
    ScoreList() {
        size = 0;}
    int getSmaller(int new_score) {
        for (int i = 0; i < size; i++) {
            if (scores[i] < new_score) {
                return i; 
            }
        }
        return -1;  
    }
    void sorting (int new_score) {
        if (size < MAX) {
            int pos = getSmaller(new_score);  
            for (int i = size; i > pos; i--) {
                scores[i] = scores[i - 1];
            }
            scores[pos] = new_score;
            size++;
        } else {
            int pos = getSmaller(new_score); 

            if (pos < max) {
                for (int i = size - 1; i > pos; i--) {
                    scores[i] = scores[i - 1];
                }
                scores[pos] = new_score;  // Insert the new score at position 'pos'
            }
        }
    }

    // Function to display the list of scores
    void traverse() {
        if (size == 0) {
            cout << "its empty " << endl;
        } else {
            for (int i = 0; i < size; i++) {
                cout << scores[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    ScoreList scoreList;

    int choice, score;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert New Score" << endl;
        cout << "2. Display Top Scores" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new score: ";
                cin >> score;
                scoreList.insertScore(score);
                break;

            case 2:
                scoreList.displayScores();
                break;

            case 3:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice, please try again!" << endl;
                break;
        }
    }

    return 0;
}

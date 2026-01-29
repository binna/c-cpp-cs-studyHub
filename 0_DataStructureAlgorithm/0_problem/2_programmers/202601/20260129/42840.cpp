#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;

    int pattern1[] = { 1, 2, 3, 4, 5 };
    int pattern1Length = 5;

    int pattern2[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int pattern2Length = 8;

    int pattern3[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int pattern3Length = 10;

    int studentScores[] = { 0, 0, 0 };
    int maxScore = 0;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == pattern1[i % pattern1Length])
        {
            studentScores[0]++;

            if (maxScore < studentScores[0])
                maxScore = studentScores[0];
        }

        if (answers[i] == pattern2[i % pattern2Length])
        {
            studentScores[1]++;

            if (maxScore < studentScores[1])
                maxScore = studentScores[1];
        }

        if (answers[i] == pattern3[i % pattern3Length])
        {
            studentScores[2]++;

            if (maxScore < studentScores[2])
                maxScore = studentScores[2];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (maxScore == studentScores[i])
            answer.push_back(i + 1);
    }
   
    return answer;
}

int main(void)
{
    for (auto num : solution({ 1,2,3,4,5 }))
    {
        cout << num << endl;
    }
    return 0;
}
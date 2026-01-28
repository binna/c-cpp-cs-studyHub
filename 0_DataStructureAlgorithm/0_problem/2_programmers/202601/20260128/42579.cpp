#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Song
{
public:
    int playCnt;
    int idx;
};

class Genre
{
public:
    string genre;
    int playCnt;
};

struct cmp
{
    bool operator() (Song o1, Song o2)
    {
        if (o1.playCnt == o2.playCnt)
            return o1.idx > o2.idx;

        return o1.playCnt < o2.playCnt;
    }

    bool operator() (Genre o1, Genre o2)
    {
        return o1.playCnt < o2.playCnt;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    priority_queue<Genre, vector<Genre>, cmp> pq;

    map<string, int> genreTable;
    map<string, priority_queue<Song, vector<Song>, cmp>> songTable;

    for (int i = 0; i < genres.size(); i++)
    {
        genreTable[genres[i]] += plays[i];
        songTable[genres[i]].push({ plays[i], i });
    }


    for (auto genre : genreTable)
    {
        pq.push({ genre.first, genre.second });
    }

    while (!pq.empty())
    {
        auto genre = pq.top();
        pq.pop();

        auto song = songTable[genre.genre];

        for (int i = 0; i < 2; i++)
        {
            if (song.empty())
                break;

            auto album = song.top();
            song.pop();

            answer.push_back(album.idx);
        }
    }

    return answer;
}

int main(void)
{
    for (auto a : solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 }))
    {
        cout << a << endl;
    }
    return 0;
}
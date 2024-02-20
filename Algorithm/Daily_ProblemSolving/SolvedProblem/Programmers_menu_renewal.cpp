#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer, max_course;
    vector<long> order, combine;
    
    int cnt, max_cnt;
    string result;

    vector<vector<string>> course_combine(course[course.size()-1] + 1, vector<string>());

    // 비트 형태로 변환
    for (int i = 0; i < orders.size(); ++i)
    {
        order.push_back(0);

        for (int j = 0; j < orders[i].size(); ++j)
        {
            order[i] += 1 << (orders[i][j] - 'A');
        }
    }

    // 주문 조합 확인
    for (int i = 0; i < order.size(); ++i)
    {
        for (int j = i + 1; j < order.size(); ++j)
        {
            combine.push_back(order[i] & order[j]);
        }
    }

    // 정답 배열 만들기
    for (int i = 0; i < combine.size(); ++i)
    {
        cnt = 0;
        result = "";

        // 문자열 형태로 변환
        for (int j = 0; j < 26; ++j)
        {
            if (combine[i] & 1 << j)
            {
                ++cnt;
                result += 65 + j;
            }
        }

        if (result != "")
        {
            cout << result << '\n';

            for (int j = 0; j < course.size(); ++j)
            {
                if (cnt == course[j])
                {
                    course_combine[cnt].push_back(result);
                    break;
                }
            }
        }
    }

    cout << "=================\n";

    for (int i = 0; i < course_combine.size(); ++i)
    {
        for (int j = 0; j < course_combine[i].size(); ++j)
        {
            cout << course_combine[i][j] << '\n';
        }

        cout << '\n';
    }


    // sorting 하고 가장 주문 수가 많았던 코스 찾기
    for (int i = 0; i < course.size(); ++i)
    {
        if(course_combine[course[i]].size() == 0)
            continue;

        sort(course_combine[course[i]].begin(), course_combine[course[i]].end());

        max_course.clear();
        max_course.push_back(course_combine[course[i]][0]);
        max_cnt = cnt = 1;

        for (int j = 1; j < course_combine[course[i]].size(); ++j)
        {
            if (course_combine[course[i]][j] == course_combine[course[i]][j - 1])
            {
                ++cnt;
            }

            else
            {
                if (max_cnt < cnt)
                {
                    max_course.clear();
                    max_cnt = cnt;
                }

                else if (max_cnt == cnt)
                {
                    max_course.push_back(course_combine[course[i]][j]);
                }

                cnt = 0;
            }
        }

        for (int j = 0; j < max_course.size(); ++j)
        {
            answer.push_back(max_course[j]);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main(void)
{
    vector<string> orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
    vector<int> course = { 2, 3, 5 };
    vector<string> ans;

    ans = solution(orders, course);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << '\n';
}

/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<long> order, duplication;
    int cnt;
    string result;

    for (int i = 0; i < orders.size(); ++i)
    {
        order.push_back(0);

        for (int j = 0; j < orders[i].size(); ++j)
        {
            order[i] += 1 << (orders[i][j] - 'A');
        }
    }

    for (int i = 0; i < order.size(); ++i)
    {
        for (int j = i + 1; j < order.size(); ++j)
        {
            duplication.push_back(order[i] & order[j]);
        }
    }

    for (int i = 0; i < duplication.size(); ++i)
    {
        cnt = 0;
        result = "";

        for (int j = 0; j < 26; ++j)
        {
            if (duplication[i] & 1 << j)
            {
                ++cnt;
                result += 65 + j;
            }
        }

        for (int j = 0; j < course.size(); ++j)
        {
            if (cnt == course[j])
            {
                answer.push_back(result);
            }
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}
*/
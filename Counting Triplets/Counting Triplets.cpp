#include <bits/stdc++.h>
#include <map>
#include <cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {

    map <long,long> ct;
    map <long,long> ct2;
    long asize = arr.size();
    map <long,long> lm;
    map <long,long> rm;
    long total = 0;

    for (long i = 0 ; i < asize ; i++)
    {
        if (arr[i] % r != 0)
        {
            lm[i] = 0;
        }
        else if ( ct.find( arr[i]/r ) != ct.end() )
        {
            lm[i] = ct[ arr[i]/r ];
        }
        else
        {
            lm[i] = 0;
        }

        if ( ct.find(arr[i]) == ct.end() )
        {
            ct[ arr[i] ] = 1;
        }
        else
        {
            ct[ arr[i] ] += 1;
        }
    }

    for (long i = asize-1 ; i >= 0 ; i--)
    {
        if ( ct2.find( arr[i]*r ) != ct2.end() )
        {
            rm[i] = ct2[ arr[i]*r ];
        }
        else
        {
            rm[i] = 0;
        }

        if ( ct2.find(arr[i]) == ct2.end() )
        {
            ct2[ arr[i] ] = 1;
        }
        else
        {
            ct2[ arr[i] ] += 1;
        }
    }

    for (long i = 0 ; i < asize ; i++)
    {
        total += (lm[i]*rm[i]);
    }

    return (long)total;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

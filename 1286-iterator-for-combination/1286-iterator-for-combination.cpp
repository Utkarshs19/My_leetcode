class CombinationIterator {
public:
    vector<string> v;
    int k = 0;

    CombinationIterator(string characters, int combinationLength) {

        int n = characters.size();

        string mask(n, '0');
        for (int i = 0; i < combinationLength; i++) {
            mask[i] = '1';
        }

        sort(mask.rbegin(), mask.rend());

        do {
            string temp = "";
            for (int i = 0; i < n; i++) {
                if (mask[i] == '1') temp += characters[i];
            }
            v.push_back(temp);
        } while (prev_permutation(mask.begin(), mask.end()));

        sort(v.begin(), v.end());
    }

    string next() {
        return v[k++];
    }

    bool hasNext() {
        return k < v.size();
    }
};
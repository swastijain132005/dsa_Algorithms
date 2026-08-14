class Trie {
private:
    struct Node {
        Node *links[26] = {nullptr};
        bool flag = false;
        int cntEndWith = 0;
        int cntPrefix = 0;

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node *node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }

        void incEnd() {
            cntEndWith++;
        }

        void incPrefix() {
            cntPrefix++;
        }

        void decEnd() {
            cntEndWith--;
            if (cntEndWith == 0)
                flag = false;
        }

        void decPrefix() {
            cntPrefix--;
        }

        int getEnd() {
            return cntEndWith;
        }

        int getPrefix() {
            return cntPrefix;
        }
    };

    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                node->put(ch, new Node());

            node = node->get(ch);
            node->incPrefix();
        }

        node->setEnd();
        node->incEnd();
    }

    bool search(string word) {
        Node *node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node *node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return true;
    }

    int countWordsEqualTo(string word) {
        Node *node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return 0;

            node = node->get(ch);
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string prefix) {
        Node *node = root;

        for (char ch : prefix) {
            if (!node->containsKey(ch))
                return 0;

            node = node->get(ch);
        }

        return node->getPrefix();
    }

    void erase(string word) {
        Node *node = root;

        for (char ch : word) {
            if (!node->containsKey(ch))
                return;

            node = node->get(ch);
            node->decPrefix();
        }

        node->decEnd();
    }
};

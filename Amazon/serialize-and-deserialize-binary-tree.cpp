class Codec {
public:
    const string MARKER = "M";

    void serializeRec(TreeNode* root, vector<string>& stream) {
        if (root == nullptr) {
            stream.push_back(MARKER);
            return;
        }

        stream.push_back(to_string(root->val));

        serializeRec(root->left, stream);
        serializeRec(root->right, stream);
    }

    string serialize(TreeNode* root) {
        vector<string> stream;
        serializeRec(root, stream);

        string result;
        for (const string& s : stream) {
            result += s + ",";
        }
        if (!result.empty())
            result.pop_back();
        return result;
    }

    TreeNode* deserializeRec(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();

        if (val == MARKER) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(val));

        node->left = deserializeRec(nodes);
        node->right = deserializeRec(nodes);

        return node;
    }

    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string item;

        while (getline(ss, item, ',')) {
            nodes.push(item);
        }

        return deserializeRec(nodes);
    }
};

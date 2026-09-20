class Codec {
public:
    // Helper for serialize
    void serializeHelper(TreeNode* root, string& result) {
        if (!root) {
            result += "null,";
            return;
        }
        result += to_string(root->val) + ",";
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    // Helper for deserialize
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front(); nodes.pop();
        if (val == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string item;

        while (getline(ss, item, ',')) {
            nodes.push(item);
        }

        return deserializeHelper(nodes);
    }
};
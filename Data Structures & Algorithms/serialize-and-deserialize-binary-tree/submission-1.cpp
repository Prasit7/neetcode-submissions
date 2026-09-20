class Codec {
public:
    // Helper to serialize the tree into a string using preorder traversal
    void serializeHelper(TreeNode* root, string& data) {
        if (!root) {
            data += "#,";
            return;
        }
        data += to_string(root->val) + ",";
        serializeHelper(root->left, data);
        serializeHelper(root->right, data);
    }

    string serialize(TreeNode* root) {
        string data;
        serializeHelper(root, data);
        return data;
    }

    // Helper to deserialize the string back to tree
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        if (val == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        queue<string> nodes;

        while (getline(ss, token, ',')) {
            nodes.push(token);
        }

        return deserializeHelper(nodes);
    }
};
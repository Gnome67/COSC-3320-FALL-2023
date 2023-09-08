struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
    TreeNode* buildTree(std::string data) {
        std::istringstream ss(data);
        return buildTreeHelper(ss);
    }
    
private:
    void encode(TreeNode* root, ostringstream& out) {
        if (root == NULL)
        {
            out << "N ";
            return;
        }
        out << root->val << " ";
        encode(root->left, out);
        encode(root->right, out);
    }
    TreeNode* decode(istringstream& in) {
        string value = "";
        in >> value;
        if (value == "N") { return NULL; }
        TreeNode* root = new TreeNode(stoi(value));
        root->left = decode(in);
        root->right = decode(in);
        return root;
    }
};
    TreeNode* buildTreeHelper(std::istringstream& ss) {
        std::string token;
        ss >> token;
        if (token == "{}") { return nullptr; }
        TreeNode* root = new TreeNode(std::stoi(token));
        root->left = buildTreeHelper(ss);
        root->right = buildTreeHelper(ss);
        return root;
    }

int main()
{
    string inputN = "";
    getline(cin, inputN);
    Codec codec, ser, deser;
    TreeNode* root = codec.buildTree(inputN);
    TreeNode* ans = deser.deserialize(ser.serialize(root));
}

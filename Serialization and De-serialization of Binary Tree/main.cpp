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

int main()
{
   string inputN = "";
   getline(cin, inputN);
   //process input
}

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
struct Node
{
    char ch;
    int frequency;
    Node *left, *right;
};
Node* getNode(char ch, int frequency, Node* left, Node* right)
{
    Node* node = new Node();
    
    node->ch = ch;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    
    return node;
}

// Comparison object to be used to order the heap
struct fixed_comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->frequency > r->frequency;
    }
};
void fixed_encode(Node* root, string str,unordered_map<char, string> &huffmanCode)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
        huffmanCode[root->ch] = str;
    
    fixed_encode(root->left, str + "0", huffmanCode);
    fixed_encode(root->right, str + "1", huffmanCode);
}
void fixed_decode(Node* root, int &index, string str)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }
    index++;
    
    if (str[index] =='0')
        fixed_decode(root->left, index, str);
    else
        fixed_decode(root->right, index, str);
}
void fixed_buildHuffTree(string text)
{
    unordered_map<char, int> frequency;
    for (char ch: text)
        frequency[ch]++;
    priority_queue<Node*, vector<Node*>> pq;
    for (auto it : frequency)
        pq.push(getNode(it.first, it.second, NULL, NULL));
    while (pq.size() != 1)
    {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top();    pq.pop();
        int sum = left->frequency + right->frequency;
        pq.push(getNode('\0', sum, left, right));
    }
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    fixed_encode(root, "", huffmanCode);
    
    cout << " character freq Length_of_the_variable fixed_length\n" << endl;
    for (auto it : huffmanCode)
        cout << it.first << " " << it.second <<" "<<endl;
    
    string str = "";
    for (char ch: text)
        str += huffmanCode[ch];
    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)str.size() - 2)
        fixed_decode(root, index, str);
}
int main()
{
    string text;
    cout << "Enter the string to encode : " << endl;
    getline (cin,text);
    fixed_buildHuffTree(text);
    cout << endl;
    return 0;
}

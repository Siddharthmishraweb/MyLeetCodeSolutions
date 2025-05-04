class Solution {
  public:
   vector<pair<int,pair<int,int >>> verticalMap;

  vector<pair<int,pair<int,int>>> horizontalDepth(TreeNode * root, int hD, int depth) {
    if (root == NULL) return verticalMap;
    if (root -> left) horizontalDepth(root -> left, hD - 1, depth + 1);
    verticalMap.push_back({ hD, { depth, root -> val }});
    if (root -> right)  horizontalDepth(root -> right, hD + 1, depth + 1);
    return verticalMap;
  }

  vector<vector<int>>verticalTraversal(TreeNode * root) {
    vector < pair < int, pair < int, int >>> hdAns = horizontalDepth(root, 0, 0);
    sort(hdAns.begin(), hdAns.end());
    map < int, vector < int >> mapi;
    for (auto & p: hdAns) {
      int hD = p.first;
      int val = p.second.second;
      mapi[hD].push_back(val);
    }
    vector < vector < int >> finalWalaAns;
    for (auto a: mapi) {
      vector < int > innerAns;
      vector < int > asdf = a.second;
      for (auto as: asdf) innerAns.push_back(as);
      finalWalaAns.push_back(innerAns);
    }
    return finalWalaAns;
  }
};
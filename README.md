void Foo()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  for_each(begin(v), end(v), [](int i) {
    cout << i << " ";
  });
}
// Outputs:
// 1 2 3

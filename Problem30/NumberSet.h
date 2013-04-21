const int MAXCOUNT=10;
typedef int Number;

class NumberSet
{
private:
  int count;
  Number items[MAXCOUNT];
public:
  NumberSet();
  Number nthLargest(int n) const;
  Number sum() const;
  int size() const;
  void print() const;
  void add(Number n);
  void remove(Number n);
}; 

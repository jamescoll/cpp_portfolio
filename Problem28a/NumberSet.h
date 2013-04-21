const int MAXCOUNT=10;
typedef int Number;

class NumberSet
{
private:
  int count;
  int max;   
  int min;
  Number items[MAXCOUNT];
public:
  NumberSet();
  Number sum() const;
  int size() const;
  int getMax() const;
  int getMin() const;
  Number get(int index) const;
  void add(Number n);
  void remove(Number n);
}; 

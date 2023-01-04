#ifndef COIN_H
#define COIN_H

class Coin extends movingObject {
  private:
    int value;      

  public:
    Coin();
    int getValue() const;
    void setValue(int v);
    ~Coin();
};

#endif

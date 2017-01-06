#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
 public:
  Shape();
  virtual ~Shape();
  virtual int GetArea() const =0;
  virtual void Draw() const;
 private:
  int m_length;
  int m_width;

};

#endif

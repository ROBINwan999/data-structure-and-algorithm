#ifndef VECTOR_H
#define VECTOR_H

template<class T>
class Vector {
public:
    Vector();

    Vector(const Vector &rhs);

    Vector &operator=(const Vector &rhs);

    T &operator[](int index) const;

    void push_back(const T &val);

    unsigned int size() const;

    void clear();

    ~Vector();

private:
    T *itr_;
    int max_size_;
    int curr_size_;

    void resize();
};

template<class T>
Vector<T>::Vector() {
    max_size_ = 5;
    curr_size_ = 0;
    itr_ = new T[max_size_];
}

template<class T>
Vector<T>::Vector(const Vector &rhs) {
    max_size_ = rhs.max_size_;
    curr_size_ = rhs.curr_size_;
    itr_ = new T[rhs.max_size_];
    memcpy(itr_, rhs.itr_, curr_size_ * sizeof(T));
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector &rhs) {
    if (this != &rhs) {
        clear();
        max_size_ = rhs.max_size_;
        curr_size_ = rhs.curr_size_;
        itr_ = new T[max_size_];
        memcpy(itr_, rhs.itr_, curr_size_ * sizeof(T));
    }

    return *this;
}

template<class T>
T &Vector<T>::operator[](int index) const {
    return itr_[index];
}

template<class T>
void Vector<T>::push_back(const T &val) {
    if (curr_size_ == max_size_)
        resize();
    itr_[curr_size_] = val;
    curr_size_++;
}

template<class T>
unsigned int Vector<T>::size() const {
    return curr_size_;
}

template<class T>
void Vector<T>::clear() {
    if (itr_ != nullptr) {
        delete[]itr_;
        itr_ = nullptr;
        curr_size_ = 0;
        max_size_ = 0;
    }
}

template<class T>
Vector<T>::~Vector() {
    clear();
}

template<class T>
void Vector<T>::resize() {
    T *temp = new T[max_size_ * 2];
    for (int i = 0; i < curr_size_; i++) {
        temp[i] = itr_[i];
    }
    max_size_ *= 2;
    delete[] itr_;
    itr_ = temp;
}

#endif
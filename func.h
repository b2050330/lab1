
#ifndef LAB1_FUNC_H
#define LAB1_FUNC_H

namespace func {

    struct Vector {
        int num; //номер элемента
        double value; //число
    };

    struct Line {
        int count;
        Vector *elem;
    };

    template<class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    void output(const char *msg, struct Line *a, int m, int n);

    struct Line *input(int &rm1, int &rm2);

    struct Line *erase(struct Line *&lines, int m);

    struct Line *sort(struct Line *line, int m, int n);

    void swap(struct Line &a, struct Line &b);
}
#endif //LAB1_FUNC_H

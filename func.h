
#ifndef LAB1_FUNC_H
#define LAB1_FUNC_H

namespace func {

    struct List{
        int num; //номер элемента
        double a; //число
        List *next;
    };

    struct Line{
        int n; //кол-во столбцов
        struct List *head;
    };

    template<class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    void output(const char *msg, struct Line *a, int m);
    struct Line *input(int &rm);
    struct Line *erase(struct Line *&lines, int m);
    struct Line *sort(struct Line *line);
    struct List *init(int num, double a);
}
#endif //LAB1_FUNC_H

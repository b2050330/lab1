#include <iostream>
#include "func.h"

namespace func {

    struct List *init(int num, double a)
    {
        auto *head = new struct List;
        head->num = num;
        head->a = a;
        head->next = nullptr;
        return (head);
    }

    struct Line *input(int &rm) {
        const char *pr = "";
        struct Line *lines = nullptr;
        int m;
        do {
            std::cout << pr << std::endl;
            std::cout << "Enter number of lines: --> ";
            pr = "You are wrong; repeat please!";
            if (getNum(m) < 0)
                return nullptr;
        } while (m < 1);

        try {
            lines = new Line[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            return nullptr;
        }
        for (int i = 0; i < m; i++) {
            lines[i].head = nullptr;
            pr = "";
            do {
                std::cout << pr << std::endl;
                std::cout << "Enter number of items in line #" << (i + 1) << " --> ";
                pr = "You are wrong; repeat please!";
                if (getNum(lines[i].n) < 0) {
                    erase(lines, i);
                    return nullptr;
                }
            } while (lines[i].n < 1);

            std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
            struct List *ptr = nullptr;

            for (int j = 0; j < lines[i].n; j++) {
                double n;
                if (getNum(n) < 0) {
                    erase(lines, i + 1);
                    return nullptr;
                }

                if (n != 0) {
                    if (lines[i].head == nullptr) {
                        lines[i].head = init(j, n);
                        ptr = lines[i].head;
                    } else {
                        auto *tmp = new List;
                        tmp->a = n;
                        tmp->num = j;
                        tmp->next = nullptr;
                        ptr->next = tmp;
                        ptr = ptr->next;
                    }
                }
            }
        }
        rm = m;
        return lines;
    }

    void output(const char *msg, struct Line *a, int m) {
        int i, j;
        std::cout << msg << ":\n";
        for (i = 0; i < m; ++i) {
            struct List *ptr = a[i].head;
            for (j = 0; j < a[i].n; ++j) {
                if (ptr->num == j) {
                    std::cout << ptr->a << " ";
                    if (ptr->next != nullptr) ptr = ptr->next;
                } else std::cout << "0" << " ";
            }
            std::cout << std::endl;
        }
    }

    struct Line *erase(struct Line *&lines, int m) {
        int i;
        struct List *prev = nullptr;
        for (i = 0; i < m; i++) {
            struct List *ptr = lines[i].head;
            while (ptr->next) {
                prev = ptr;
                ptr = ptr->next;
                delete (prev);
            }
            delete (ptr);
        }
        delete[] (lines);
        return nullptr;
    }

    void swap(struct Line *a, struct Line *b) {
        struct Line temp = *a;
        *a = *b;
        *b = temp;
    }

    double get_first(struct Line *line) {
        if (line->head->num == 0) {
            return line->head->a;
        } else return 0.0;
    }

    struct Line *sort(struct Line *line) {
        int k;
        if (get_first(line) > 0) k = 1;
        else k = 0;
        if (line->n < 2)
            return line;
        for (int i = 0; i < line->n; ++i) {
            for (int j = 0; j < line->n - i; ++j)
                if (get_first(&line[j + 1]) < get_first(&line[j]))
                    swap(&line[j + 1], &line[j]);
        }
        return line;
    }
}
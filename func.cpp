#include <iostream>
#include "func.h"

namespace func {

    struct Line *input(int &rm1, int &rm2) {
        const char *pr = "";
        struct Line *lines = nullptr;
        int m, n;
        do {
            std::cout << pr << std::endl;
            std::cout << "Enter number of lines: --> ";
            pr = "You are wrong; repeat please!";
            if (getNum(m) < 0)
                return nullptr;
        } while (m < 2);

        pr = "";
        do {
            std::cout << pr << std::endl;
            std::cout << "Enter number of columns: --> ";
            pr = "You are wrong; repeat please!";
            if (getNum(n) < 0)
                return nullptr;
        } while (n < 2);

        try {
            lines = new Line[m];
        }
        catch (std::bad_alloc &ba) {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            return nullptr;
        }

        auto *buf = new double[n];

        for (int i = 0; i < m; i++) {
            std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
            int index, count = 0;
            double value;

            for (int j = 0; j < n; j++) {
                buf[j] = 0.0;
            }

            pr = "You are wrong; repeat please!";

            std::cout << "  Enter index for new element (natural >= 0).\nIf you want to stop entering elements "
                         "for this line,please enter -1 " << std::endl;
            while (getNum(index) < 0 || index < -1) {
                std::cout << pr << std::endl;
            }

            if (index != -1) {
                std::cout << "Enter value for new element (double)" << std::endl;
                while (getNum(value) < 0) {
                    std::cout << pr << std::endl;
                }
            }

            while (index >= 0 && count < n) {
                if (buf[index] == 0.0) {
                    count++;
                    buf[index] = value;
                } else std::cout << "Element with that index already exists" << std::endl;

                std::cout << "Enter index for new element (natural >= 0).\n If you want to stop entering elements "
                             "for this line,please enter -1 " << std::endl;
                while (getNum(index) < 0 || index < -1) {
                    std::cout << pr << std::endl;
                }

                if (index != -1) {
                    std::cout << "Enter value for new element (double)" << std::endl;
                    while (getNum(value) < 0) {
                        std::cout << pr << std::endl;
                    }
                }
            }

            if (count == n) std::cout << "Were entered max amount of elements" << std::endl;

            lines[i].count = count;
            lines[i].elem = new Vector[count];
            int j = 0;
            for (int k = 0; k < n; ++k) {
                if (buf[k] != 0.0) {
                    lines[i].elem[j].num = k;
                    lines[i].elem[j].value = buf[k];
                    j++;
                }
            }
        }
        delete[] buf;
        rm1 = m;
        rm2 = n;
        return lines;
    }

    void output(const char *msg, struct Line *a, int m, int n) {
        int i, j, k;
        std::cout << msg << ":\n";
        for (i = 0; i < m; ++i) {
            k = 0;
            for (j = 0; j < n; ++j) {
                if (a[i].count >= k && a[i].elem[k].num == j) {
                    std::cout << a[i].elem[k].value << " ";
                    ++k;
                } else std::cout << "0" << " ";;
            }
            std::cout << std::endl;
        }
    }

    struct Line *erase(struct Line *&lines, int m) {
        int i;
        for (i = 0; i < m; i++) {
            delete[] lines[i].elem;
        }
        delete[] lines;
        return nullptr;
    }

    void swap(struct Line *a, struct Line *b) {
        struct Line temp = *a;
        *a = *b;
        *b = temp;
    }

    double get_first(struct Line *line) {
        if (line->elem[0].num == 0) {
            return line->elem[0].value;
        }else return 0;
    }

    struct Line *sort(struct Line *line, int m, int n) {
        int k;
        if (get_first(&line[0]) <= 0) k = 1;
        else k = 0;

        if (m < 2)
            return line;

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < m - i - 1; ++j) {
                if (k == 1) {
                    if (get_first(&line[j + 1]) < get_first(&line[j]))
                        swap(&line[j + 1], &line[j]);
                } else {
                    if (get_first(&line[j + 1]) > get_first(&line[j]))
                        swap(&line[j + 1], &line[j]);
                }
            }
        }
        return line;
    }
}
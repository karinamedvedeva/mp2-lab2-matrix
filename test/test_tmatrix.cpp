#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m(5), m1(5);
    for (int i = 0; i < m.GetSize(); i++)
    {
        for (int j = i; j < m.GetSize(); j++)
        {
            m[i][j] = i + j;
            m1[i][j] = m[i][j];
        }
    }
    EXPECT_EQ(m1, m);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix <int> m(5), m1(5);
    for (int i = 0; i < m.GetSize(); i++)
    {
        for (int j = i; j < m.GetSize(); j++)
        {
            m[i][j] = i + j;
            m1[i][j] = m[i][j];
        }
    }
    EXPECT_NE(&m[0][0], &m1[0][0]);
}

TEST(TMatrix, can_get_size)
{
    TMatrix <int> m(5);
    EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);
    m[0][0] = 5;
    EXPECT_EQ(5, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix <int> m(5);
    ASSERT_ANY_THROW(m[0][-1]=5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix <int> m(5);
    ASSERT_ANY_THROW(m[0][6] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix <int> m(5);
    for (int i = 0; i < m.GetSize(); i++)
    {
        for (int j = i; j < m.GetSize(); j++)
        {
            m[i][j] = i + j;
        }
    }
    ASSERT_NO_THROW (m = m);
    EXPECT_EQ(m, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix <int> m(5), m1(5);
    for (int i = 0; i < m.GetSize(); i++)
    {
        for (int j = i; j < m.GetSize(); j++)
        {
            m[i][j] = i + j;
        }
    }
    m1 = m;
    EXPECT_EQ(m1, m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix <int> m(5), m1(10);
    m1 = m;
    EXPECT_EQ(m.GetSize(), m1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix <int> m(5), m1(10);
    for (int i = 0; i < m.GetSize(); i++)
    {
        for (int j = i; j < m.GetSize(); j++)
        {
            m[i][j] = i + j;
        }
    }
    ASSERT_NO_THROW(m1 = m);
    EXPECT_EQ(m, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix <int> m(5);
    for (int i = 0; i < m.GetSize(); i++)
    {
        for (int j = i; j < m.GetSize(); j++)
        {
            m[i][j] = i + j;
        }
    }
    TMatrix <int> m1=m;
    EXPECT_EQ(1, m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix <int> m(5);
    for (int i = 0; i < m.GetSize(); i++)
    {
        for (int j = i; j < m.GetSize(); j++)
        {
            m[i][j] = i + j;
        }
    }
    EXPECT_EQ(1, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix <int> m(5), m1(10);
    EXPECT_EQ(1, m != m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix <int> a(5), b(5), c(5);
    for (int i = 0; i < a.GetSize(); i++)
    {
        for (int j = i; j < a.GetSize(); j++)
        {
            a[i][j] = i;
            b[i][j] = i;
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    c = a + b;
    EXPECT_EQ(c, a + b);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix <int> a(5), b(10);
    ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix <int> a(5), b(5), c(5), res(5);
    for (int i = 0; i < a.GetSize(); i++)
    {
        for (int j = i; j < a.GetSize(); j++)
        {
            a[i][j] = i;
            b[i][j] = i;
            c[i][j] = a[i][j] - b[i][j];
            res[i][j] = 0;
        }
    }
    EXPECT_EQ(c, res);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix <int> a(5), b(10);
    ASSERT_ANY_THROW(a - b);
}


import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Aditya Zope
 */
public class Main
{
    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA
    {
        private long[] a;
        private long[] tree;
        private long[] lazy;

        private void build(long a[], int node, int start, int end)
        {

            if (start == end)
                tree[node] = a[start];
            else
            {
                int mid = (start + end) / 2;
                build(a, 2 * node, start, mid);
                build(a, 2 * node + 1, mid + 1, end);
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            }
        }

        private long query(int node, int start, int end, int l, int r)
        {
            if (start > end || start > r || end < l)
                return 0;
            if (lazy[node] != 0)
            {
                tree[node] += (end - start + 1) * lazy[node];
                if (start != end)
                {
                    lazy[2 * node] += lazy[node];
                    lazy[2 * node + 1] += lazy[node];
                }
                lazy[node] = 0;
            }
            if (l <= start && end <= r)
                return tree[node];
            else
            {
                int mid = (start + end) / 2;
                return query(2 * node, start, mid, l, r) +
                        query(2 * node + 1, mid + 1, end, l, r);
            }
        }

        private void update(int node, int start, int end, int l, int r, long v)
        {
            if (start > end || start > r || end < l)
                return;
            if (lazy[node] != 0)
            {
                tree[node] += (end - start + 1) * lazy[node];
                if (start != end)
                {
                    lazy[2 * node] += lazy[node];
                    lazy[2 * node + 1] += lazy[node];
                }
                lazy[node] = 0;
            }

            if (l <= start && r >= end)
            {
                tree[node] += (end - start + 1) * v;
                if (start != end)
                {
                    lazy[2 * node] += v;
                    lazy[2 * node + 1] += v;
                }
            } else
            {
                int mid = (start + end) / 2;
                update(2 * node, start, mid, l, r, v);
                update(2 * node + 1, mid + 1, end, l, r, v);
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out)
        {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            a = new long[n];
            long f[] = new long[m];
            tree = new long[4 * Math.max(n, m)];
            lazy = new long[4 * Math.max(n, m)];
            for (int i = 0; i < n; i++)
            {
                a[i] = in.nextLong();
            }
            Arrays.fill(lazy, 0);
            ArrayList<Query> q = new ArrayList<>();
            for (int i = 0; i < m; i++)
            {
                q.add(new Query(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
            }
            build(f, 1, 0, m - 1);
            for (int i = 0; i < k; i++)
            {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                update(1, 0, m - 1, l, r, 1);
            }
            for (int i = 0; i < m; i++)
            {
                f[i] = query(1, 0, m - 1, i, i);
            }
            Arrays.fill(lazy, 0);
            build(a, 1, 0, n - 1);
            for (int i = 0; i < m; i++)
            {
                update(1, 0, n - 1, q.get(i).s, q.get(i).e, (q.get(i).v) * f[i]);
            }
            for (int i = 0; i < n; i++)
            {
                a[i] = query(1, 0, n - 1, i, i);
                out.print(a[i] + " ");
            }
            out.println();
        }

        private class Query
        {
            int s;
            int e;
            int v;

            Query(int s, int e, int v)
            {
                this.s = s;
                this.e = e;
                this.v = v;
            }

        }

    }

    static class OutputWriter
    {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream)
        {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer)
        {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects)
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0)
                {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println()
        {
            writer.println();
        }

        public void close()
        {
            writer.close();
        }

    }

    static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int read()
        {
            if (numChars == -1)
            {
                throw new InputMismatchException();
            }
            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt()
        {
            int c = read();
            while (isSpaceChar(c))
            {
                c = read();
            }
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long nextLong()
        {
            int c = read();
            while (isSpaceChar(c))
            {
                c = read();
            }
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do
            {
                if (c < '0' || c > '9')
                {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c)
        {
            if (filter != null)
            {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c)
        {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);

        }

    }
}


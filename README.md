# Hiatus & Scatha

## Tools
```bash
grep -rnw '/path/to/somewhere/' -e 'pattern'
```

## Test
```bash
./bin/utest --help
./bin/utest --gtest_color=yes --gtest_filter=NoiseTest.Tutorial_2 --gtest_repeat=10
```

## GIT
```bash
git rebase --interactive v13.6.1
git show --pretty="" --name-only 6c1c8ec90d468aa553136bd0011954515ff69464
git diff -U0 HEAD^ | ./tools/clang-format-diff.py -p1 -i
git am -3 < changes.patch
```

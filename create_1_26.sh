for i in {1..26}
do
	./tetrogen $i
done
for i in {1..26}
do
	./test tetrimino_testfile_$i
done
rm -f tetrimino_testfile_*

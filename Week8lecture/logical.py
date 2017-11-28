import cs50

c= cs50.get_char()
if c == 'y' or c=='Y':
    print('Yes')
elif c=='n' or c== 'N':
    print('No')
else:
    print('Error')

import struct

global output


def combination( num, remain, white):
    if num == 1:
        white.append(remain)
        #print white
        global output
        for num in white:
            output.write( struct.pack("<b", num))
        #output.write(" ".join(map( str, white))+"\n")
    else:
        for black in xrange( 1, remain-num+2):
            new_white = white[:]
            new_white.append( black)
            combination( num-1, remain-black, new_white)


if __name__=="__main__":
    global output
    for board in xrange( 5, 33):
        output = open("combb"+str(board)+".txt","wb")
        for num in xrange( 1, (board+1)/2):
            output.write( struct.pack("<b",-2))
            for rem in xrange( num, board-num):
                combination( num, rem, [])    
                output.write( struct.pack("<b", -1))
        output.close()
        
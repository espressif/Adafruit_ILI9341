from PIL import Image
import sys

def is_jpg(filename):
    data = open(filename,'rb').read(11)
    if data[:4] != b'\xff\xd8\xff\xe0' and data[:4]!=b'\xff\xd8\xff\xe1': 
        return False
    if data[6:] != b'JFIF\x00' and data[6:] != b'Exif\x00': 
        return False
    return True

def is_jpg2(filename):
    try:
        i=Image.open(filename)
        return i.format =='JPEG'
    except IOError:
        return False

def main():

    if len(sys.argv)<1:
        print('Argument Failed! please use jpg file name (without \'.jpg\')')

    print('Image Name',sys.argv[1]+'.jpg')

    file_name = str(sys.argv[1])
    code_h = file_name+".h"
    image_jpg = file_name+".jpg"
    row_len = 16

    assert is_jpg(image_jpg)
    assert is_jpg2(image_jpg)

    f = open(image_jpg,'rb')
    f_read = f.read()


    list_file = list(f_read)
    file_len = len(list_file)

    head_str1 = '//File: '+image_jpg+', Size: '+str(file_len)+'\n'
    head_str2 = '#define '+image_jpg[:-4]+'_jpg_len '+str(file_len)+'\n'
    head_str3 = 'const uint8_t '+image_jpg[:-4]+'_jpg[] PROGMEM = {'+'\n'

    file_object = open(code_h, 'w')
    file_object.truncate();
    file_object.writelines([head_str1,head_str2,head_str3])

    count_len = 0

    for i in range(file_len):
        if count_len == 16:
            count_len = 0
            file_object.write('\n')
        count_len+=1
        file_object.write('0x'+'{0:02X}'.format(int(list_file[i])))
        if i == file_len-1:
            break
        file_object.write(', ')
    file_object.write('\n};')
    file_object.close( )
    print('Succeed!')

main()
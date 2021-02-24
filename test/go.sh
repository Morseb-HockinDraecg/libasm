nasm -f macho64 *.s
ld -macosx_version_min 10.7.0 -o exec *.o
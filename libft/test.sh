FILES="ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup"
SRCSDIR="/Users/damouyal/42Projects/libft/srcs/"
LIBHEADER="/Users/damouyal/42Projects/libft/headers/"
LIBDIR="/Users/damouyal/42Projects/libft/"

for TFILE in $FILES
do
	clear
	echo "** Testing $TFILE"
	gcc -Wall -Wextra -Werror -L${LIBDIR} -lft -I${LIBHEADER} test.c ${TFILE}.c
	./a.out
	echo "** Test of $TFILE complete. Press key to proceed..."
	read -rsn1
	echo
done


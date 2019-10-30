TESTS = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen \
	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr \
	ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup \
		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd \
		ft_putendl_fd ft_putnbr_fd 
BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap 
PROJECTDIR = "../../repo/"
LIBDIR = "${PROJECTDIR}"
INCLUDES = "${PROJECTDIR}"
SRCSDIR = "${PROJECTDIR}"
SRCSFP = ${SRCS:%=${SRCSDIR}%.c}
TESTSNAMES = ${TESTS:%=%.test}

all : libft ${TESTSNAMES}
#@echo $+

libft : FORCE
	$(MAKE) -C ${LIBDIR}
libbonus : FORCE
	$(MAKE) -C ${LIBDIR} bonus

bonus : libbonus ${BONUS:%=%.btest}

%.btest : FORCE
	@echo "No test available for $* sorry" ; \
	norminette ${SRCSDIR}$*.c ; \
	read -n 1 ; \
	vim ${SRCSDIR}$*.c ; \
	read -n 1 ; \
	clear 

%.test : FORCE
	@if [[ "${TESTS}" =~ (^|[[:space:]])"$*"($|[[:space:]]) ]] ; then \
		 clear ; \
		 norminette ${SRCSDIR}$*.c ; \
		 echo "* Press any key to continue..." ; \
		 read -n 1 ; \
		 clear ; \
		 echo "* Ready to compile test $*" ; \
		 gcc -Wall -Wextra -Werror -lft -L${LIBDIR} -I${INCLUDES} $*.c ${SRCSDIR}$*.c test.c ; \
		 echo "* Compilation ended with code $$?. Press any key to continue..." ; \
		 read -n 1 ; \
		 ./a.out|tee $*.test ; \
		 echo "* Press any key to continue..." ; \
		 read -n 1 ; else \
		 echo "no test available" ; \
		 fi ;

FORCE :

clean :
	rm -f *.test
	rm -f a.out

.PHONY : all clean  

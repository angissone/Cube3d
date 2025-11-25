# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    targets.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 14:28:42 by ybouroga          #+#    #+#              #
#    Updated: 2025/11/25 17:00:43 by ybouroga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TODO 2 meme regle ?
debug: C_FLAGS += $(DBG_FLAGS)
debug: re

#TODO Idem
asan: C_FLAGS += $(ASAN_FLAGS)
asan: re

TEST_FILE_0 = test_files/V0.rt
TEST_FILE_1 = test_files/V1.rt
TEST_FILE_2 = test_files/V2.rt
TEST_FILE_3 = test_files/V3.rt
TEST_FILE_4 = test_files/V4.rt

0:
	clear && make && $(EXE) $(TEST_FILE_0)
1:
	clear && make && $(EXE) $(TEST_FILE_1)
2:
	clear && make && $(EXE) $(TEST_FILE_2)
3:
	clear && make && $(EXE) $(TEST_FILE_3)
4:
	clear && make && $(EXE) $(TEST_FILE_4)

b:
	clear && make bonus && $(EXE_BONUS) $(TEST_FILE_4)

vg:
	clear && make && \
  valgrind \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --trace-children=yes \
  --track-fds=yes \
  $(EXE) $(TEST_FILE_0)

vgb:
	clear && make bonus && \
  valgrind \
  --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --trace-children=yes \
  --track-fds=yes \
$(EXE_BONUS) $(TEST_FILE_0)


git:
	git pull && git add $(shell find . -type f \( -name "*.c" -o -name "*.h" \) \
  -not -path "./test2/*" \
  -not -path "./OBJ/*" \
  -not -path "./tester/*") .gitignore Makefile \
  mk/includes.mk mk/sources.mk mk/targets.mk \
  test_files/* \
  && git commit -m "$(m)" && git push

.PHONY: all bonus clean fclean re 0 1 2 3 4 debug asan vg vgb git

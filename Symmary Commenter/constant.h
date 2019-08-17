#ifndef CONSTANT_H
#define CONSTANT_H

#define DEFAULT_WIN_TITLE           "Summary Commenter"

enum tab_index{
    TAB_GLOBAL = 0,
    TAB_FLAG = 1,
    TAB_DESCRIPT = 2,
    TAB_ISSUE = 3,
    TAB_REF = 4,
    TAB_EXCLUDE = 5,
    TAB_PREVIEW = 6,
};

#define SAVE_RECENT_PATH    5

#define CSH_START_COMMENT   "#--------------------------------------------------------\n#\n# This file is created by comment helper 2019-08-10\n#\n#--------------------------------------------------------"

#define IS_DIV(flag) flag == FlagType::SUBDIV || flag == FlagType::SUPDIV

#endif // CONSTANT_H



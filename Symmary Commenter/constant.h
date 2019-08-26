#ifndef CONSTANT_H
#define CONSTANT_H

// ==============================+===============================================================
// shortcuts

#define FlagTable_t             ui->flagTblWidget
#define DescTable_t             ui->descTblWidget
#define IssueTable_t            ui->issueTblWidget
#define RefTable_t              ui->referenceTbl
#define ExcludeTable_t          ui->excludeTbl

#define Extension_t             ui->extensionEdit->text()
#define ProjectPath_t           ui->pathEdit->text()
#define Author_t                ui->authorEdit->text()
#define Separator_t             ui->separatorEdit->text()
#define StartTag_t              ui->sTagEdit->text()
#define EndTag_t                ui->eTagEdit->text()
#define SupDiv_t                ui->supDivEdit->toPlainText()
#define SubDiv_t                ui->subDivEdit->toPlainText()
#define Email_t                 ui->emailEdit->text()
#define Telep_t                 ui->telepEdit->text()
#define GithubAcc_t             ui->githubEdit->text()
#define Team_t                  ui->teamEdit->text()
#define Memo_t                  ui->memoEdit->toPlainText()
#define ProjectName_t           ui->projectNameEdit->text()

#define IsDescNumbering_t       ui->actionDesc_Numbering->isChecked()
#define IsIssueNumbering_t      ui->actionIssue_Numbering->isChecked()
#define IsRefURLNumbering_t      ui->actionRefe_URL_Numbering->isChecked()
#define IsRecursiveTraversal_t  ui->actionRecursive_Traversal->isChecked()

#define IsDivBySeparator_t      divBySeparator->isChecked()
#define IsDivByStartEndTag_t    divByStartEndTag->isChecked()

// ==============================+===============================================================
// enum

enum TabIndex{
    TAB_GLOBAL      =  0,
    TAB_FLAG        =  1,
    TAB_DESCRIPT    =  2,
    TAB_ISSUE       =  3,
    TAB_REF         =  4,
    TAB_EXCLUDE     =  5,
    TAB_PREVIEW     =  6,
};

enum CommentStyle{
    Undefined       = -1,
    DivBySeparator      ,
    DivByStartEndTag    ,
};

// ==============================+===============================================================
// constants

#define DEFAULT_WIN_TITLE   "Summary Commenter"

#define SAVE_RECENT_PATH    5

#define CSH_START_COMMENT   "#--------------------------------------------------------\n#\n# This file is created by comment helper \n#\n#--------------------------------------------------------"

#define PROJECT_SETTING_FILE_EXT "scps" // Summary Commenter Project Setting file

#define PROJECT_LATELY_OPEN_EXT  "sclately"

#define PROJECT_WORKED_FILE_EXT  "scproj"

// ==============================+===============================================================

#endif // CONSTANT_H



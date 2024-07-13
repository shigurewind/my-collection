#pragma once

#define Message_h (13)
#define Message_w (50)

extern bool isMessageMode;



void InitUI(void);
void UninitUI(void);
void UpdateUI(void);
void DrawUI(void);

void SetUI(int y, int x, char data);

void DrawMessage(void);
void SetMessage(int m);//���̓��b�Z�[�W�̎��
void ClearMessage(void);

void updateHP();

void updateArrowNum();

void updateHeartFragments();


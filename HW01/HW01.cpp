// main.cpp
#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main()
{
    int status[4] = { 0, 0, 0, 0 }; // [0]:HP, [1]:MP, [2]:공격력, [3]:방어력
    int HPPotion = 0, MPPotion = 0;

    do
    {
        cout << "HP와 MP를 입력하세요 (각 50 초과):";
        cin >> status[0] >> status[1];
        if (status[0] <= 50 || status[1] <= 50)
        {
            cout << "50이하로 입력이 불가합니다. 다시 입력하세요.\n";
        }
    } while (status[0] <= 50 || status[1] <= 50);

    do
    {
        cout << "공격력과 방어력을 입력하세요.(각 0 초과)";
        cin >> status[2] >> status[3];
        if (status[2] <= 0 || status[3] <= 0)
        {
            cout << "0이하로 입력이 불가합니다. 다시 입력하세요.\n";
        }
    } while (status[2] <= 0 || status[3] <= 0);

    // 기본 포션 지급
    setPotion(5, &HPPotion, &MPPotion);

    // 3. 메뉴판 무한 루프
    int choice;

    while (true)
    {
        cout << "\n--- 메뉴 선택 ---\n";
        cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기\n";
        cout << "선택: ";
        cin >> choice;

        if (choice == 0) {
            cout << "프로그램을 종료합니다.\n";
            break;
        }

        switch (choice)

        {
        case 1: // MP 포션 사용 (요구사항대로 1번이 MP UP)
            if (MPPotion > 0)

            {
                status[1] += 20;
                MPPotion--;
                cout << "MP가 20 올랐습니다. (남은 포션: " << MPPotion << ")\n";
            }
            else cout << "포션이 부족합니다!\n";
            break;
        case 2: // HP 포션 사용
            if (HPPotion > 0)
            {
                status[0] += 20;
                HPPotion--;
                cout << "HP가 20 올랐습니다. (남은 포션: " << HPPotion << ")\n";
            }
            else cout << "포션이 부족합니다!\n";
            break;
        case 3: // 공격력 2배
            status[2] *= 2; // 또는 status[2] = status[2] + status[2];
            cout << "공격력이 2배가 되었습니다!\n";
            break;
        case 4: // 방어력 2배
            status[3] <<= 1; // 비트 시프트 연산(<< 1)으로도 2배 가능합니다.
            cout << "방어력이 2배가 되었습니다!\n";
            break;
        case 5: // 현재 능력치 출력
            cout << "[현재 스탯] HP: " << status[0] << ", MP: " << status[1]
                << ", ATK: " << status[2] << ", DEF: " << status[3] << "\n";
            cout << "[남은 포션] HP포션: " << HPPotion << ", MP포션: " << MPPotion << "\n";
            break;
        case 6: // 레벨 업 (포션 충전)
            HPPotion++;
            MPPotion++;
            cout << "레벨 업! 포션을 각각 1개씩 추가했습니다.\n";
            break;
        default:
            cout << "잘못된 번호입니다.\n";
        }
    }
    return 0;
}

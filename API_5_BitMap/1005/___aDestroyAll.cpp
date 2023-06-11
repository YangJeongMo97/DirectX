#include "___aDestroyAll.h"
//// ÀÏ°ý Ç¥¸é ÆÄ±«
void ___aDestroyAll()
{
	for (int i = 0; i < 4; i++) {
		__geReleaseSurface(&g_sfCharacterStand[i]);
		__geReleaseSurface(&g_sfCharacterWalk[i]);
	}
	for (int i = 0; i < 6; i++)
		__geReleaseSurface(&g_sfCloud[i]);
	for (int i = 0; i < 2; i++) {
		__geReleaseSurface(&g_sfCharacterJump[i]);
		__geReleaseSurface(&g_sfCharacterDown[i]);
	}
	__geReleaseSurface(&g_sfBG);
	__geReleaseSurface(&g_sfBack);
}
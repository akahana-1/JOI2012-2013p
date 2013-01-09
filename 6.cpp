#include <iostream>
using namespace std;

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int H, W, K;
char field[50][50+1];

int dfs(int x, int y, int r, int res) {
	if (x == W-1 && y == H-1 && r == 0) return res;
	if ('1' <= field[y][x] && field[y][x] <= '9') res += field[y][x]-'0';

	int t[4] = {};
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (0 <= nx && nx < W && 0 <= ny && ny < H && field[ny][nx] != '#') {
			if (i < 2) t[i] = dfs(nx, ny, r, res);
			if (i >= 2 && r > 0) t[i] = dfs(nx, ny, r-1, res);
		}
	}

	return max( max( max( t[0], t[1] ), t[2] ), t[3] );
}

int main() {
	cin >> H >> W >> K;
	for (int i = 0; i < H; ++i) cin >> field[i];

	cout << dfs(0, 0, K, 0) << endl;

	return 0;
}
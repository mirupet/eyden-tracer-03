#include "Scene.h"

#include "ShaderEyelight.h"
#include "ShaderPhong.h"


void CScene::ParseOBJ(const std::string& fileName)
{
	std::cout << "Parsing OBJFile : " << fileName << std::endl;

	std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 1, 1));
	std::ifstream fin(fileName);
	std::vector<Vec3f> vertices;

	while(!fin.eof()){
		char c;
		fin >> c;

		if(c == 'v'){
			float x, y, z;
			fin >> x >> y >> z;
			vertices.push_back(Vec3f(x, y, z) * 100);
		}
		else{
			int v1, v2, v3;
			fin >> v1 >> v2 >> v3;

			Add(std::make_shared<CPrimTriangle>(vertices[v1 - 1], vertices[v2 - 1], vertices[v3 - 1], pShader));
		}
	}

	fin.close();

	std::cout << "Finished Parsing" << std::endl;
}


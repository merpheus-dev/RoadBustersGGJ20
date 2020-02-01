#include "AssetImporter.h"
RenderObject* AssetImporter::Load(const char* filePath)
{
	const aiScene* scene = aiImportFile(filePath, aiProcessPreset_TargetRealtime_MaxQuality);

	if (!scene)
	{
		std::cout << "Could not load file " << filePath << std::endl;
		return nullptr;
	}

	const aiMesh* model = scene->mMeshes[0];

	RenderObject* pack = new RenderObject();
	pack->mesh = new Mesh();
	pack->material = new Material();

	pack->mesh->vertices_size = model->mNumVertices * 3;
	pack->mesh->vertices = new float[model->mNumVertices * 3];
	pack->mesh->normals_size = model->mNumVertices * 3;
	pack->mesh->normals = new float[model->mNumVertices * 3];

	pack->material->texCoordSize = model->mNumVertices * 2;
	pack->material->texCoord = new float[model->mNumVertices * 2];

	for (int i = 0; i < model->mNumVertices; i++) {
		pack->mesh->vertices[i * 3] = model->mVertices[i].x;
		pack->mesh->vertices[i * 3 + 1] = model->mVertices[i].y;
		pack->mesh->vertices[i * 3 + 2] = model->mVertices[i].z;

		if (model->HasNormals()) {
			pack->mesh->normals[i * 3] = model->mNormals[i].x;
			pack->mesh->normals[i * 3 + 1] = model->mNormals[i].y;
			pack->mesh->normals[i * 3 + 2] = model->mNormals[i].z;
		}

		if (model->HasTextureCoords(0)) {
			pack->material->texCoord[i * 2] = model->mTextureCoords[0][i].x;
			pack->material->texCoord[i * 2 + 1] = 1 - model->mTextureCoords[0][i].y;
		}
	}

	pack->mesh->indices_size = model->mNumFaces * 3;
	pack->mesh->indices = new unsigned int[model->mNumFaces * 3];

	for (int i = 0; i < model->mNumFaces; i++) {
		pack->mesh->indices[i * 3] = model->mFaces[i].mIndices[0];
		pack->mesh->indices[i * 3 + 1] = model->mFaces[i].mIndices[1];
		pack->mesh->indices[i * 3 + 2] = model->mFaces[i].mIndices[2];
	}

	return pack;
}

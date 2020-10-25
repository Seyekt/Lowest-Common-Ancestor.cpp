#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lowestcommonancestor/lowestcommonancestor.cpp"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LCATest {

	TEST_CLASS(LCATest) {

	public:
		
		TEST_METHOD(LCATestCase0) {
			Node * root = newNode(1);
			root->left = newNode(2);
			root->right = newNode(3);
			root->left->left = newNode(4);
			root->left->right = newNode(5);
			root->right->left = newNode(6);
			root->right->right = newNode(7);

			int LCA = findLCA(root, 4, 5);
			int LCA2 = findLCA(root, 4, 6);

			Assert::AreEqual(LCA, 2);
			Assert::AreEqual(LCA2, 1);
		}

	};
}
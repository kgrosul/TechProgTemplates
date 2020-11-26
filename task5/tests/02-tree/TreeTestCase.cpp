//
// Created by akhtyamovpavel on 5/1/20.
//


#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include "TreeTestCase.h"
#include "Tree.h"

TEST(TreeTestCase, InvalidPathTest) {
  ASSERT_THROW(GetTree("no-such-path", true), std::invalid_argument);
}

TEST(TreeTestCase, NotDirectoryTest) {
  boost::filesystem::ofstream file("test_file");
  file << "hello_world";
  ASSERT_THROW(GetTree("test_file", true), std::invalid_argument);
  boost::filesystem::remove_all("test_file");
}


TEST(TreeTestCase, SimpleTest) {
  boost::filesystem::create_directory("test_directory");
  ASSERT_NO_THROW(GetTree("test_directory", false));
  boost::filesystem::remove_all("test_directory");
}

TEST(TreeTestCase, EqualTest) {
  FileNode node1;
  node1.name = "test_folder_1";
  node1.is_dir = true;

  FileNode node2;
  node2.name = "test_folder_1";
  node2.is_dir = true;

  ASSERT_TRUE(node1 == node2);
}


TEST(TreeTestCase, NotEqualNameTest) {
  FileNode node1;
  node1.name = "test_folder_1";
  node1.is_dir = true;

  FileNode node2;
  node2.name = "test_folder_2";
  node2.is_dir = true;

  ASSERT_FALSE(node1 == node2);
}


TEST(TreeTestCase, NotEqualIsDirTest) {
  FileNode node1;
  node1.name = "test_folder_1";
  node1.is_dir = true;

  FileNode node2;
  node2.name = "test_folder_1";
  node2.is_dir = false;

  ASSERT_FALSE(node1 == node2);
}

TEST(TreeTestCase, NotEqualChildrenTest) {
  FileNode node1;
  node1.name = "test_folder_1";
  node1.is_dir = true;

  FileNode node2;
  node2.name = "test_folder_1";
  node2.is_dir = true;
  node2.children.push_back(node2);

  ASSERT_FALSE(node1 == node2);
}


TEST(TreeTestCase, OnlyDirsTest) {
  FileNode node1;
  node1.name = "test_folder_1";
  node1.is_dir = true;
  boost::filesystem::create_directory("test_folder_1");

  boost::filesystem::ofstream file("test_folder_1/test_file");
  file << "hello_world";
  file.close();

  FileNode node2;
  node2.name = "test_folder_2";
  node2.is_dir = true;
  node1.children.push_back(node2);
  boost::filesystem::create_directory("test_folder_1/test_folder_2");

  ASSERT_TRUE(GetTree("test_folder_1", true) == node1);
  boost::filesystem::remove_all("test_folder_1");
}


TEST(TreeTestCase, FilesTest) {
  FileNode node1;
  node1.name = "test_folder_1";
  node1.is_dir = true;
  boost::filesystem::create_directory("test_folder_1");

  FileNode node3;
  node3.name = "test_file";
  node3.is_dir = false;
  node1.children.push_back(node3);
  boost::filesystem::ofstream file("test_folder_1/test_file");
  file << "hello_world";
  file.close();

  FileNode node2;
  node2.name = "test_folder_2";
  node2.is_dir = true;
  node1.children.push_back(node2);
  boost::filesystem::create_directory("test_folder_1/test_folder_2");

  boost::filesystem::remove_all("test_folder_1/.DS_Store");

  ASSERT_TRUE(GetTree("test_folder_1", false) ==  node1);
  boost::filesystem::remove_all("test_folder_1");
}


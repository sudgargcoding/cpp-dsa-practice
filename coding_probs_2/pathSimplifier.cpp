#include <iostream>
#include <vector>
#include <sstream>

std::string simplifyPath(std::string path) {
    std::stringstream stream(path);
    std::string segment;
    std::vector<std::string> stack;

    // Split the path by '/'
    while (std::getline(stream, segment, '/')) {
        if (segment == "." || segment.empty()) {
            continue;
        } else if (segment == "..") {
            // Handle "..", which means go up one level
            if (!stack.empty()) {
                stack.pop_back();
            }

        } else {
            // Push the directory name onto the stack
            std::cout << "segment is = " << segment << std::endl;
            stack.push_back(segment);
        }
    }

    // Construct the simplified path
    std::string simplified_path;

    // Add root slash
    if (stack.empty()) {
        return "/";
    }

    // Create output
    for (const std::string& dir : stack) {
        std::cout << "dir is = " << dir << std::endl;
        simplified_path += "/" + dir;
    }

    return simplified_path;
}

int main() {
    std::string path = "/.../a/../b/c/../d/./";
    std::string simplified = simplifyPath(path);
    std::cout << "Simplified Path: " << simplified << std::endl; // Output: "/c"
    return 0;
}
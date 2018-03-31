#include <Input/Commands/UseCommand.h>

using namespace Core;

void UseCommand::execute(GameObject* actor) {
    actor->Use();
}
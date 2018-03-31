#include <Input/Commands/UseCommand.h>

using namespace Core;

void UseCommand::execute(GameObjects::Pawn* actor) {
    actor->Use();
}
import EnvironmentSetupTask from "./env/setup"

export const taskCodes = {
    ENV_0: 'ENV-0'
}

const taskComponents = {
    [taskCodes.ENV_0]: EnvironmentSetupTask
}

export const buildTask = (code, props) => {
    
    const TaskComponent = taskComponents[code];

    if(!TaskComponent){
        return undefined;
    }

    return <TaskComponent code={code} {...props} />
}
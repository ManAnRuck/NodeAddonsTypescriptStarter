import { testAddon } from "./AddonBindings";

export const Hello = (): void => {
    return testAddon.Hello();
}

export const Prime = (num: number): number => {
    return testAddon.Prime(num);
}